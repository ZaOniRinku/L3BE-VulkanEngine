#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

void main() {
  float ambientLight = 1.0;
  vec3 lightColor = vec3(1.0, 1.0, 1.0);
  vec3 lightResult = ambientLight * lightColor;
  outColor = texture(texSampler, fragTexCoord);
  outColor *= vec4(lightResult, 1.0);
}