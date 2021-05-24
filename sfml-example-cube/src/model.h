class Cube
{
	private:
		float angle = 0;
	public:
	void update()
	{	
		glTranslatef(0.0f, 0.0F, -1.33f);

		angle += 0.4;
		glPushMatrix();	
		glRotatef(angle, 1.0f, 0.0f, 0.0f);
		glRotatef(angle, 0.0f, 1.0f, 0.0f);
		glRotatef(angle, 0.0f, 0.0f, 1.0f);	
		draw();
		glPopMatrix();
	}
	void draw()
	{
		glBegin(GL_QUADS);
	 
			// Top face
		  	glColor3f(   0.5f, 0.0f,  0.5f );  // Purple
		  	glVertex3f(  0.35f, 0.35f, -0.35f );  // Top-right of top face
		  	glVertex3f( -0.35f, 0.35f, -0.35f );  // Top-left of top face
		  	glVertex3f( -0.35f, 0.35f,  0.35f );  // Bottom-left of top face
		 	glVertex3f(  0.35f, 0.35f,  0.35f );  // Bottom-right of top face
		 
			// Bottom face
			glColor3f(   0.0f,  1.0f,  0.0f ); // Green
			glVertex3f(  0.35f, -0.35f, -0.35f ); // Top-right of bottom face
			glVertex3f( -0.35f, -0.35f, -0.35f ); // Top-left of bottom face
			glVertex3f( -0.35f, -0.35f,  0.35f ); // Bottom-left of bottom face
			glVertex3f(  0.35f, -0.35f,  0.35f ); // Bottom-right of bottom face
		 
			// Front face
			glColor3f(   0.0f,  0.0f, 1.0f );  // Blue
			glVertex3f(  0.35f,  0.35f, 0.35f );  // Top-Right of front face
			glVertex3f( -0.35f,  0.35f, 0.35f );  // Top-left of front face
			glVertex3f( -0.35f, -0.35f, 0.35f );  // Bottom-left of front face
			glVertex3f(  0.35f, -0.35f, 0.35f );  // Bottom-right of front face
		 
			// Back face
			glColor3f(   0.5f,  0.5f,  0.0f ); // Orange
			glVertex3f(  0.35f, -0.35f, -0.35f ); // Bottom-Left of back face
			glVertex3f( -0.35f, -0.35f, -0.35f ); // Bottom-Right of back face
			glVertex3f( -0.35f,  0.35f, -0.35f ); // Top-Right of back face
			glVertex3f(  0.35f,  0.35f, -0.35f ); // Top-Left of back face
		 
			// Left face
			glColor3f(   0.0f,  0.0f,  0.0f);  // Black
			glVertex3f( -0.35f,  0.35f,  0.35f);  // Top-Right of left face
			glVertex3f( -0.35f,  0.35f, -0.35f);  // Top-Left of left face
			glVertex3f( -0.35f, -0.35f, -0.35f);  // Bottom-Left of left face
			glVertex3f( -0.35f, -0.35f,  0.35f);  // Bottom-Right of left face
		 
			// Right face
			glColor3f(   1.0f,  0.0f,  0.0f);  // Red
			glVertex3f(  0.35f,  0.35f,  0.35f);  // Top-Right of left face
			glVertex3f(  0.35f,  0.35f, -0.35f);  // Top-Left of left face
			glVertex3f(  0.35f, -0.35f, -0.35f);  // Bottom-Left of left face
			glVertex3f(  0.35f, -0.35f,  0.35f);  // Bottom-Right of left face
		
		// End of GL calls
		glEnd();
	}
};
