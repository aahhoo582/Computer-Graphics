#define GLFW_DLL
#include<GLFW/glfw3.h>
#include<iostream>
#include<Windows.h>
#include<cmath>

using namespace std;

int main()
{
	HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	const unsigned int red = 4, green = 2;

	int width = 1280, height = 720;
	const char* title = "Render Engine";
	GLFWwindow* window = NULL;

	SetConsoleTextAttribute(handleOut, green);

	if (!glfwInit())
	{
		SetConsoleTextAttribute(handleOut, red);
		cout << "Error: GLFW was not initialized successfully!" << endl;
		SetConsoleTextAttribute(handleOut, green);
		return -1;
	}

	if (!(window = glfwCreateWindow(width, height, title, NULL, NULL)))
	{
		SetConsoleTextAttribute(handleOut, red);
		cout << "Error: Rendering window could not be created!" << endl;
		SetConsoleTextAttribute(handleOut, green);
		glfwTerminate();
		return -1;
	}
	else
	{
		glfwMakeContextCurrent(window);
		glfwMaximizeWindow(window);
		glfwSwapInterval(1);
	}


    ///double nowTime = 0;
	float vertices[2][3][3] = {
		///Vectors
		{
			{-0.5f, -0.5f, 0.0f},
			{0.0f, 0.5f, 0.0f},
			{0.5f, -0.5f, 0.0f}
		},
		///Colors
		{
			{1.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 1.0f}
		}
	};

	glClearColor(0.7f, 0.8f, 1.0f, 1.0f);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices[0]);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, vertices[1]);

	while (!glfwWindowShouldClose(window))
	{
	    glViewport(320, 180, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		///glShadeModel(GL_FLAT);
		/**nowTime = glfwGetTime();
		glLoadIdentity();
		glScalef(abs(sin(nowTime)), abs(sin(nowTime)), 1);
		glRotatef(sin(nowTime) * 45, 0.0f, 0.0f, 1.0f);
		glTranslatef(sin(nowTime), cos(nowTime), 0);**/
		glRotatef(1.0f, 0.0f, 1.0f, 0.0f);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
