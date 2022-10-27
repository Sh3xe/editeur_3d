#version 330 core

in vec2 texture_coords;
uniform sampler2D u_texture;

void main()
{
	gl_FragColor = texture(u_texture, texture_coords);
}