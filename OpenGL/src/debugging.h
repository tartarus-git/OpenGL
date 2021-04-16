#pragma once

// OpenGL related includes.
#include <GL/glew.h>

// Other includes.
#include <iostream>

#ifdef _DEBUG

#define ASSERT(condition) if (!(condition)) { __debugbreak(); }

inline void clearGLErrors() { while (glGetError()); }
inline bool getGLError(const char* functionName, const char* file, unsigned int line) {
	bool noErrors = true;
	GLenum errorCode;
	while (errorCode = glGetError()) {
		std::cout << "[OpenGL error] " << "err: " << errorCode << " : " << functionName << " in " << file << " at " << line << std::endl;
		noErrors = false;
	}
	return noErrors;
}
#define DEBUG(function) clearGLErrors(); function; ASSERT(getGLError(#function, __FILE__, __LINE__))

#else
#define DEBUG(function) function
#endif