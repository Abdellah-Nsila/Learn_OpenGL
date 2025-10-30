#include "config.h"

class Material
{
	public:
		Material(const char *filename);
		~Material();

		void	init();
		void	setTextureParameter(GLenum target, GLenum pname, GLint param);
		int		loadTexture(GLenum target, GLint level, GLint internalFormat, GLint border, GLenum type);
		void	bind();
		void	unbind();
		void	deleteBuffer();
		void	setMateria();
		void	use(int textureUnit);
	
	private:
		unsigned int	ID;
		const char		*filename;
};
