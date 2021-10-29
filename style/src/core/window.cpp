#ifdef STYLE_PLATFORM_WINDOWS
#include <windows.h>  // fixing warning C4005: 'APIENTRY': macro redefinition
#else
#define APIENTRY
#endif

#include "SDL2/SDL.h"
#include "core/window.hpp"
#include "engine.hpp"
#include "glad/glad.h"
#include "log.hpp"

namespace style::core {

Window::Window() : window_(nullptr) {}

Window::~Window() {
  if (window_) {
    Shutdown();
  }
}

bool Window::Create() {
  bool ret = true;
  window_ = SDL_CreateWindow("Style Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
                             SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
  if (!window_) {
    STYLE_ERROR("Error creationg window: {}", SDL_GetError());
    ret = false;
  }

#ifdef STYLE_PLATFORM_MAC
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
#endif
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  SDL_SetWindowMinimumSize(window_, 200, 200);

  gl_context_ = SDL_GL_CreateContext(window_);
  if (gl_context_ == nullptr) {
    STYLE_ERROR("Error creating OpenGL context: {}", SDL_GetError());
    return false;
  }

  gladLoadGLLoader(SDL_GL_GetProcAddress);

  return ret;
}

void Window::Shutdown() {
  SDL_DestroyWindow(window_);
  window_ = nullptr;
}

void Window::PumpEvents() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    switch (e.type) {
      case SDL_QUIT:
        Engine::GetInstance().Quit();
        break;

      default:
        break;
    }
  }
}

}  // namespace style::core
