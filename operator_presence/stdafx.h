#pragma once


//
// SDL2 + GLEW
//

#include "GL\glew.h"
#include "SDL.h"
#include "SDL_syswm.h"


//
// Qt
//

#include <QtCore\qcoreapplication.h>
#include <QtCore\qobject.h>
#include <QtGui\qimage.h>
#include <QtGui\qopenglbuffer.h>
#include <QtGui\qopenglshaderprogram.h>
#include <QtGui\qopengltexture.h>
#include <QtGui\qopenglvertexarrayobject.h>


//
// C++
//

#include <array>
#include <atomic>
#include <cassert>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <vector>


//
// OculusVR
//

#include <OVR_CAPI.h>
#include <OVR_CAPI_GL.h>


//
// OpenCV
//

#include <opencv2\core\mat.hpp>


//
// Helpers
//

#include "scope_guard.h"
#include "scoped_enum_as_integer.h"
#include "threadsafe_queue.h"
