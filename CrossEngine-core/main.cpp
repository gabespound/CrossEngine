#include "src/graphics/window.h"
#include "src/math/math.h"

int main()
{
	using namespace cross;
	using namespace graphics;
	using namespace math;

	Window window("Sparky!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec3 vector(1.0f, 2.0f, 3.0f);

	mat4 position = mat4::translation(vec3(2, 3, 4));
	
	vec4 column = position.columns[3];

	std::cout << column << std::endl;

	while (!window.closed())
	{
		window.clear();
		//std::cout << vector << std::endl;
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -.5f);
		glVertex2f(-0.5f, .5f);
		glVertex2f(0.5f, .5f);
		glVertex2f(0.5f, -.5f);
		glEnd();
#endif
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}

	return 0;
}