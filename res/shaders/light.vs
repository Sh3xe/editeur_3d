#version 330 core

layout(location=0) in vec3 a_position;
layout(location=1) in vec3 a_normal;
layout(location=2) in vec2 a_texture_coords;

uniform mat4 u_mvp;

out vec3 normal;
out vec2 texture_coords;

void main()
{
	normal = a_normal;
	texture_coords = a_texture_coords;
	gl_Position = u_mvp * vec4(a_position.xyz, 1.0);
}