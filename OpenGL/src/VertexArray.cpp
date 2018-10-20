#include "VertexArray.h"

#include "VertexBufferLayout.h"
#include "Renderer.h"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

//TODO: fix possible errors when used with multiple elements in one buffer
void VertexArray::AddBuffer(unsigned int attributeIndex, const VertexBuffer & vb, const VertexBufferLayout & layout)
{
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	const auto& element = elements[0];
	GLCall(glEnableVertexAttribArray(attributeIndex));
	GLCall(glVertexAttribPointer(attributeIndex, element.count, element.type, element.normalized , layout.GetStride(), (const void*)offset));
	//offset += element.count * VertexBufferElement::GetSizeOfType(element.type);

}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));

}

unsigned int VertexArray::getId() {
	return m_RendererID;
}
