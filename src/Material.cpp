#include "Material.hpp"
#include "stb_image.h"

Material::Material(const char *filename) : filename(filename)
{
	std::ifstream	textureFile;

	textureFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	try 
	{
		textureFile.open(filename);
		textureFile.close();
	}
	catch(const std::ifstream::failure& e)
	{
		std::cerr << "ERROR::MATERIAL::TEXTURE_NOT_SUCCESFULLY_LOAD::" << e.what() << std::endl;
	}
	this->setMateria();
}

Material::~Material()
{
	if (ID)
		glDeleteTextures(1, &ID);
}

void	Material::init()
{
	glGenTextures(1, &ID);
}

void	Material::setTextureParameter(GLenum target, GLenum pname, GLint param)
{
	glTexParameteri(target, pname, param);
}

int	Material::loadTexture(GLenum target, GLint level, GLint internalFormat, GLint border, GLenum type)
{
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *pixels = stbi_load(this->filename, &width, &height, &nrChannels, 0);
	std::cout << width << " " <<   height << std::endl;

	if (pixels)
	{
		GLenum texFormat = (nrChannels == 4) ? GL_RGBA : GL_RGB;
		glTexImage2D(target, level, internalFormat, width, height, border, texFormat, type, pixels);
		glGenerateMipmap(target);
	}
	else
	{
		std::cerr << "Failed to load texture: " << this->filename << std::endl;
		return (EXIT_FAILURE);
	}
	stbi_image_free(pixels);
	return (EXIT_SUCCESS);
}

void	Material::bind()
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

void	Material::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void	Material::deleteBuffer()
{
	if (ID)
		glDeleteTextures(1, &ID);
}

void	Material::setMateria()
{
	this->init();
	this->bind();
	this->setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	this->setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	this->setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	this->setTextureParameter(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	this->loadTexture(GL_TEXTURE_2D, 0, GL_RGB, 0, GL_UNSIGNED_BYTE);
}

void	Material::use(int textureUnit)
{
	GLint	maxTextureUnit;

    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureUnit);
	
	if (textureUnit < 0 || textureUnit > maxTextureUnit)
	{
		std::cout << "incorrect texture unit: " << textureUnit
		<< " Max active Texture Unit is: " << maxTextureUnit << std::endl;
	}
	if (ID)
	{
		glActiveTexture(GL_TEXTURE0 + textureUnit);
		this->bind();
	}
}
