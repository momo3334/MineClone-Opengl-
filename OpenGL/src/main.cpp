#include<GL\glew.h>
#include <GLFW/glfw3.h>

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
#include "objLoader/obj_loader.h"
#include "Block.h"
#include "Mesh.h"
#include "Input.h"


#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#define WIDTH  960
#define HEIGHT  540

Transform transformation(glm::vec3(0.0f, 0.0f, 0.0f));
Camera camera(glm::vec3(0, 0, 5), 70.0f, (float)WIDTH / (float)HEIGHT, 0.1f, 1000.0f);

bool keys[GLFW_KEY_LAST + 1];
bool mouseButtons[GLFW_MOUSE_BUTTON_LAST + 1];
char direction = ' ';



int main(void);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

void updateKeyboard(GLFWwindow* window);


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);


	if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;
	
		//Setting up the camera



		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		//GLCall(glEnable(GL_CULL_FACE));
		//GLCall(glCullFace(GL_BACK));

		GLCall(glEnable(GL_DEPTH_TEST));



		//Building a meshe and storing data in VertexBuffers

		//Shader shader("res/Shaders/Basic.shader");
		//shader.Bind();
		//shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

		//Texture texture("res/textures/sprite.png");
		//texture.Bind();
		//shader.SetUniform1i("u_Texture", 0);

		World world(5, 5, 5);

		world.CreateWorld();

		world.GenerateChunk();
		//Mesh Cube = Mesh(Mesh::Cube, shader);
		//
		//Cube.Load();

		Renderer renderer;

		renderer.Init();

		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		GLCall(glfwSetKeyCallback(window, key_callback));
		GLCall(glfwSetCursorPosCallback(window, cursor_position_callback));

		float r = 0.0f;
		float f = 0.0f;
		double x = 0.0f;
		double y = 0.0f;
		float increment = 0.1f;
		GLCall(glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED));

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			renderer.Clear();

			ImGui_ImplGlfwGL3_NewFrame();

			//r = 0.0f;

			updateKeyboard( window);





				//glm::mat4 mvp = camera.GetViewProjection() * transformation.GetModel();

				//renderer.pushTranformationMatrix(camera.GetViewProjection());

				renderer.Draw(camera.GetViewProjection());

			//r += increment;

			{

				static int counter = 0;
				ImGui::SliderFloat3("Foward vector", &camera.m_Foward.x, 0.0 , 4.0);            // Edit 1 float using a slider from 0.0f to 1.0f    
				ImGui::SliderFloat("r", &r, 0.0,3.0);            // Edit 1 float using a slider from 0.0f to 1.0f    
				ImGui::SliderFloat("f", &f, 0, 6.28318);            // Edit 1 float using a slider from 0.0f to 1.0f  
				//if (ImGui::RadioButton("Button",true))  direction = 'u';
				//else direction = ' ';
				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			}

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		
		}

	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//std::cout << glfwGetKey(window, GLFW_KEY_RIGHT) << std::endl;

	//key released
	if (action == GLFW_RELEASE){
		keys[key] = false;
	}

	//key pressed
	if (action == GLFW_PRESS) {
		keys[key] = true;
	}
}

void cursor_position_callback(GLFWwindow * window, double xpos, double ypos)
{
	//GLCall(glfwGetCursorPos(window, &x, &y));
	camera.Rotate(xpos, ypos);
}

void updateKeyboard(GLFWwindow* window) {
	if (keys[GLFW_KEY_RIGHT])
		transformation.GetRot().y += 0.02f;
	if (keys[GLFW_KEY_LEFT])
		transformation.GetRot().y -= 0.02f;
	if (keys[GLFW_KEY_UP])
		transformation.GetRot().x += 0.02f;
	if (keys[GLFW_KEY_DOWN])
		transformation.GetRot().x -= 0.02f;
	if (keys[GLFW_KEY_ESCAPE])
		glfwSetWindowShouldClose(window, 1);
	if (keys[GLFW_KEY_W])
		camera.MoveFoward();
	if (keys[GLFW_KEY_S])
		camera.MoveBackward();
	if (keys[GLFW_KEY_A])
		camera.MoveStrafeLeft();
	if (keys[GLFW_KEY_D])
		camera.MoveStrafeRight();
	if (keys[GLFW_KEY_LEFT_CONTROL])
		camera.MoveDown();
	if (keys[GLFW_KEY_LEFT_SHIFT])
		camera.MoveUp();

}

void InitInputArrays() {
	/*Setting keys array to false*/
	for (unsigned int i = 0; i < GLFW_KEY_LAST + 1; i++)
	{
		keys[i] = false;
	}

	/*Setting mouse buttons array to false*/
	for (unsigned int i = 0; i < GLFW_KEY_LAST + 1; i++)
	{
		mouseButtons[i] = false;
	}
}

