# CMakeList.txt : projet CMake pour Iroël Project, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.10)

# Activez Rechargement à chaud pour les compilateurs MSVC si cela est pris en charge.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Iroel_Project")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")


add_subdirectory(libraries/SDL EXCLUDE_FROM_ALL)
set(IMGUI_SOURCES
    libraries/imgui/imgui.cpp
    libraries/imgui/imgui_draw.cpp
    libraries/imgui/imgui_tables.cpp
    libraries/imgui/imgui_widgets.cpp
    libraries/imgui/backends/imgui_impl_sdl3.cpp
    libraries/imgui/backends/imgui_impl_opengl3.cpp
)

find_package(OpenGL REQUIRED)
# Ajoutez une source à l'exécutable de ce projet.
add_executable (Iroel_Project "Iroel_Project.cpp" "Iroel_Project.h" "defs.h"    "Geometry/Coordinate.cpp" "Geometry/Edge.h" "Geometry/Edge.cpp"  "Geometry/Triangle.cpp" "Geometry/Geometry.h" "Camera.h" "Camera.cpp" ${IMGUI_SOURCES} "RendererGL.h" "RendererGL.cpp")

#set_property(TARGET Iroel_Project PROPERTY WIN32_EXECUTABLE TRUE)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Iroel_Project PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.

target_link_libraries(Iroel_Project PRIVATE 
                                    SDL3::SDL3
                                    OpenGL::GL)
target_include_directories(Iroel_Project PRIVATE
    libraries/imgui
    libraries/imgui/backends
)
