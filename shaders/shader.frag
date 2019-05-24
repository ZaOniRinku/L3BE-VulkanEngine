#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;
layout(location = 2) in float fragAmbientLightValue;
layout(location = 3) in vec3 fragAmbientLightColor;
layout(location = 4) in vec3 fragNormal;
layout(location = 5) in vec3 fragEye;
layout(location = 6) in vec3 fragLightDirection;

layout(location = 0) out vec4 outColor;

void main() {
  float intensity = max(dot(fragNormal, fragLightDirection), 0.0);
  vec3 lightResult = fragAmbientLightValue * fragAmbientLightColor;
  vec4 diffuse = texture(texSampler, fragTexCoord);
  outColor = max(diffuse * intensity, diffuse * vec4(lightResult, 1.0));
}
