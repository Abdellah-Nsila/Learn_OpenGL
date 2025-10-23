#pragma once

#include "string"
#include "iostream"
#include <stdint.h>

namespace	Core
{

	struct WindowSpecification
	{
		std::string	Title;
		uint32_t	Width = 1080;
		uint32_t	Height = 720;
		bool		IsResizable = true;
		bool		VSync = true;
	};

	class Window
	{
		public:
			Window(const WindowSpecification& specification = WindowSpecification());
			~Window();
			void	Create();
			void	Destroy();
			void	Update();

			bool	ShouldClose() const;

			GLFWwindow	*GetHandle() const;
		private:
			WindowSpecification	m_Specification;
			//TODO: Include Libraries and Link them
			GLFWwindow* m_Handle = nullptr;
	};
	
	Window::Window(/* args */)
	{
	}
	
	Window::~Window()
	{
	}
	
}
