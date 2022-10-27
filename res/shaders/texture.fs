#version 330 core

in vec3 normal;
in vec2 texture_coords;

uniform sampler2D u_texture;

void main()
{
	//gl_FragColor = texture(u_texture, texture_coords);
	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}