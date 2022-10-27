#include "gldebug.hpp"
#include "core/logger.hpp"

#include <GL/glew.h>

bool _log_gl_errors(int line, const char* file)
{
	bool ok = true;
	GLenum error_flag = GL_NO_ERROR;

	while((error_flag = glGetError()) != GL_NO_ERROR) {
		SD_ERROR("OpenGL Error in file:", file, "at line", line, ":");
		switch(error_flag) {
			case GL_INVALID_ENUM:
				SD_ERROR("GL_INVALID_ENUM");
				break;
			case GL_INVALID_VALUE:
				SD_ERROR("GL_INVALID_VALUE");
				break;
			case GL_INVALID_OPERATION:
				SD_ERROR("GL_INVALID_OPERATION");
				break;
			case GL_OUT_OF_MEMORY:
				SD_ERROR("GL_OUT_OF_MEMORY");
				break;
			case GL_INVALID_FRAMEBUFFER_OPERATION:
				SD_ERROR("GL_INVALID_FRAMEBUFFER_OPERATION");
				break;
			default: break;
		}

		ok = false;
	}

	return ok;
}
