#include "ShadowShader.h"
#include "Base/Vertex.h"
#include "Base/Light.h"

ShadowShader * ShadowShader::shader = nullptr;

ShadowShader * ShadowShader::GetInstance()
{
	if (shader == nullptr)
		shader = new ShadowShader();
	return shader;
}

glm::vec4 ShadowShader::FragmentShader(const VertexOut & f)
{
	return glm::vec4(1.0f);
}




