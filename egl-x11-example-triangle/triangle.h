static void DrawTriangle(struct window *window)
{
	static const char *vertex_source =
		"attribute vec4 position;\n"
		"attribute vec4 color;\n"
		"\n"
		"varying vec4 vcolor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"  gl_Position = position;\n"
		"  vcolor = color;\n"
		"}\n";

	static const char *fragment_source =
		"precision mediump float;\n"
		"varying vec4 vcolor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"  gl_FragColor = vcolor;\n"
		"}\n";

	static GLfloat vertices[] = {
		 0.0f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
	};

	static GLfloat colors[] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
	};

	GLuint vertex, fragment, program;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertex_source, NULL);
	glCompileShader(vertex);

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragment_source, NULL);
	glCompileShader(fragment);

	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	glBindAttribLocation(program, 0, "position");
	glBindAttribLocation(program, 1, "color");

	printf("=== Calling glLinkProgram()\n");
	glLinkProgram(program);
	glFlush();
	printf("=== Calling glUseProgram()\n");
	glUseProgram(program);
	glFlush();
	printf("=== calling glViewport()\n");
	glViewport(0, 0, window->width, window->height);
	glFlush();
	printf("=== calling glClearColor()\n");
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glFlush();
	printf("=== calling glClear()\n");
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();

	printf("=== Calling glVertexAttribPointer(0)\n");
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
	glFlush();
	printf("=== Calling glEnableVertexAttribArray(0)\n");
	glEnableVertexAttribArray(0);
	glFlush();
	printf("=== Calling glVertexAttribPointer(1)\n");
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, colors);
	glFlush();
	printf("=== Calling glEnableVertexAttribArray(1)\n");
	glEnableVertexAttribArray(1);
	glFlush();
	printf("=== Calling glDrawArrays(GL_TRIANGLES, 0, 3)\n");
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glFlush();
	printf("=== calling eglSwapBuffers()\n");
	eglSwapBuffers(window->display->egl, window->surface);
	glFlush();
	printf("=== done\n");
}
