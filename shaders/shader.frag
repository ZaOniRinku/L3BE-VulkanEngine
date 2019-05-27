#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;

layout(location = 0) in vec3 fragNormal;
layout(location = 1) in vec3 fragEye;
layout(location = 2) in vec3 fragLightDir;
layout(location = 3) in vec2 fragTexCoord;
layout(location = 4) in vec3 fragAmbient;
layout(location = 5) in float fragDistance;

layout(location = 0) out vec4 outColor;

void main() {
  vec3 n = normalize(fragNormal);
  vec3 e = normalize(fragEye);
  vec3 l = normalize(fragLightDir);

  float intensity = max(dot(n, l), 0.0);

  vec4 diffuse = texture(texSampler, fragTexCoord);
  if (fragDistance > 10.0) {
    outColor = vec4(fragAmbient, 0.0) * diffuse;
  }
  else {
    outColor = max(intensity * diffuse, vec4(fragAmbient, 0.0) * diffuse);
  }
}
