#version 330 core

in vec2 v_TexCoord;

layout(location = 0) out vec4 color;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main() {
    vec4 texColor = texture(u_Texture, v_TexCoord);
    color = texColor + vec4(u_Color.x, u_Color.y, u_Color.z, 0);
    //color = vec4(v_TexCoord.x, v_TexCoord.y, 0, 1);
}