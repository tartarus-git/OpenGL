#include "ShaderProgram.h"

#include <GL/glew.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "debugging.h"

ShaderProgram::ShaderProgram() {
	id = glCreateProgram();
}

std::string ShaderProgram::includeShader(const char* file) {
	std::ifstream f(file);
	std::stringstream source;
	char buffer[256];
	while (true) {
		f.read(buffer, sizeof(buffer));
		int bytesRead = f.gcount();
		source.write(buffer, bytesRead);
		if (bytesRead < sizeof(buffer)) { break; }
	}
	f.close();
	return source.str();														// TODO: Find out how this reference stays valid even though the source stream should technically be released at the end of this function. Invisible copy constructor or something?
}

// Compile a single shader from source.
unsigned int ShaderProgram::compileShader(std::string source, unsigned int type) {
	unsigned int id = glCreateShader(type);
	const char* cStrSource = source.c_str();
	glShaderSource(id, 1, &cStrSource, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);										// i means integer, v means vector/array (in this case basically just this pointer).
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader." << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

void ShaderProgram::loadVertexShader(const char* file) {
	vertexShader = compileShader(includeShader(file), GL_VERTEX_SHADER);
}

void ShaderProgram::loadFragmentShader(const char* file) {
	fragmentShader = compileShader(includeShader(file), GL_FRAGMENT_SHADER);
}

void ShaderProgram::finalize() {
	glAttachShader(id, vertexShader);
	glAttachShader(id, fragmentShader);
	glLinkProgram(id);
	glValidateProgram(id);

	// TODO: Validation stuff, research what glValidateProgram even does.

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(id);
}

void ShaderProgram::bind() {
	DEBUG(glUseProgram(id));
}