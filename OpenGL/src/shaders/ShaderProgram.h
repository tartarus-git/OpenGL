#pragma once

#include <string>					// TODO: You should probably include this everywhere where you use std::string just to avoid confusion.

class ShaderProgram
{
private:
	unsigned int vertexShader;
	unsigned int fragmentShader;

	std::string includeShader(const char* file);
	unsigned int compileShader(std::string source, unsigned int type);
protected:
	unsigned int id;

	ShaderProgram();

	void loadVertexShader(const char* file);
	void loadFragmentShader(const char* file);

	void finalize();

	~ShaderProgram();
public:
	void bind();
};