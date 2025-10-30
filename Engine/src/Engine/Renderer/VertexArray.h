#pragma once

namespace Engine
{

	class VertexArray
	{
		public:
			virtual			~VertexArray() = default;
			virtual void	Init() = 0;
			virtual void	Bind() = 0;
			virtual void	Unbind() = 0;
			virtual void	DeleteBuffer() = 0;

		private:
			/* data */
	};
	

	

}
