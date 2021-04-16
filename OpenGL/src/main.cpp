// OpenGL related includes.
#define GLEW_STATIC																	// This is defined so that GLEW knows that it is being statically linked.
#include <GL/glew.h>																// This has to be included before GLFW.
#include <GLFW/glfw3.h>

// OpenGL wrapper includes.
#include "buffers/VertexBuffer.h"
#include "buffers/IndexBuffer.h"
#include "buffers/VertexBufferLayout.h"
#include "buffers/VertexArray.h"
#include "shaders/BasicShader.h"
#include "entities/Entity.h"
#include "rendering/entities/EntityRenderer.h"
#include "textures/Texture.h"

// Other includes.
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>

// Debugging.
#include "debugging.h"

int main() {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit()) { return -1; }

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Universe", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// 1 sets the refresh rate to my monitors refresh rate or something. TODO: Research more about this function.
	glfwSwapInterval(1);

	// Initialize GLEW library.
	if (glewInit() != GLEW_OK) {
		std::cout << "Error!" << std::endl;
		ASSERT(false);
	}

	// Print OpenGL version.
	std::cout << glGetString(GL_VERSION) << std::endl;

	// Vertex positions for triangle.
	float positions[] = {						// Not just positions anymore, also texture coords.
		-0.5f, -0.5f, 0,	0,
		 0.0f,  0.5f, 0.5f, 1,
		 0.5f, -0.5f, 1,	0
	};

	unsigned int indicesList[] = {
		0, 1, 2
	};

	{																			// Scope makes sure that stack-allocated objects get terminated before GLFW destroys the OpenGL context. This will avoid errors.

		DEBUG(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
		DEBUG(glEnable(GL_BLEND));

		Entity mainEntity;

		// Buffer setup.
		VertexBuffer vertices(positions, sizeof(positions), GL_STATIC_DRAW);

		VertexBufferLayout layout(2, GL_FLOAT, 4 * sizeof(float), 0);
		VertexBufferLayout uvLayout(2, GL_FLOAT, 4 * sizeof(float), 2 * sizeof(float));

		mainEntity.model.setVertices(std::move(vertices));
		mainEntity.model.vertices.put(0, layout);
		mainEntity.model.vertices.enable(0);
		mainEntity.model.vertices.put(1, uvLayout);
		mainEntity.model.vertices.enable(1);

		IndexBuffer indices(indicesList, sizeof(indicesList), GL_STATIC_DRAW);				// TODO: Figure out a way to put this into the model without accidentally releasing the resources.

		mainEntity.model.setIndices(std::move(indices));

		Texture mainEntityTexture("res/textures/test.png");
		mainEntity.model.setTextures(&mainEntityTexture, 1);

		BasicShader shader;

		EntityRenderer mainEntityRenderer;
		mainEntityRenderer.shader = &shader;

		shader.loadColor(0, 1, 0, 1);
		float greenValue = 1;
		bool mode = false;

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window)) {
			/* Render here */
			mainEntityRenderer.clear();

			// Draw triangle.
			mainEntityRenderer.render(mainEntity);

			if (mode) {
				greenValue += 0.1f;
				if (greenValue > 0.99999f && greenValue < 1.00001f) {
					mode = false;
				}
			}
			else {
				greenValue -= 0.1f;
				if (greenValue > -0.00001f && greenValue < 0.00001f) {
					mode = true;
				}
			}
			shader.loadColor(0, greenValue, 0, 1);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

	}

	glfwTerminate();
	return 0;
}