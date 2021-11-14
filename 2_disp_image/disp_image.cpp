#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main( void )
{
    GLFWwindow *window;

		int wWidth = 800, wHeight = 600;
		
    
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( wWidth, wHeight, "Display Image", NULL, NULL );
    
    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
			glfwGetWindowSize(window, &wWidth, &wHeight);

			glViewport( 0.0f, 0.0f, wWidth, wHeight ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
			glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
			glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
			glOrtho( 0, wWidth, 0, wHeight, 0, 1 ); // essentially set coordinate system
			glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
			glLoadIdentity( ); // same as above comment

			float vertices[] =
			{
				(float) wWidth, (float) wHeight, 0.0, // top right corner
				0, (float) wHeight, 0.0, // top left corner
				0, 0, 0.0, // bottom left corner
				(float) wWidth, 0, 0.0 // bottom right corner
			};
      glClear( GL_COLOR_BUFFER_BIT );
      
      // Render OpenGL here
      glEnableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're using a vertex array for fixed-function attribute
      glVertexPointer( 3, GL_FLOAT, 0, vertices ); // point to the vertices to be used
      glDrawArrays( GL_QUADS, 0, 4 ); // draw the vertixes
      glDisableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're finished using the vertex arrayattribute
      
      
      // Swap front and back buffers
      glfwSwapBuffers( window );
      
      // Poll for and process events
      glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;
}