#version 430 core

flat in vec3 FrontColor;
flat in vec3 BackColor;

in vec2 TexCoord;

out vec4 FragColor;

void main()
{
	const float scale = 100.0f;
	bvec2 toDiscard = greaterThan( fract(TexCoord * scale), vec2(0.2f, 0.2f));

	if (all(toDiscard))
		discard;

	if (gl_FrontFacing)
		FragColor = vec4(FrontColor, 1.0f);
	else
		FragColor = mix(vec4(BackColor, 1.0f), vec4(0.0f, 1.0f, 1.0f, 1.0f), 0.5f);
}