cmake_minimum_required(VERSION 3.20)
project(ing1-projet-2021-22-dofus-arena-team-aa C)

set(CMAKE_C_STANDARD 99)

add_executable(ing1-projet-2021-22-dofus-arena-team-aa main.c menu.c menu.h arene.c arene.h interface0.c interface0.h echap.c echap.h classe.c classe.h chargement.c chargement.h interfaceClasse.c interfaceClasse.h joueur.c joueur.h Sorts.h Sorts.c coordonneesISO.h)

IF(WIN32)
    target_link_libraries(ing1-projet-2021-22-dofus-arena-team-aa -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
    INCLUDE_DIRECTORIES(/usr/local/Cellar/allegro/5.2.7.0/include)
    LINK_DIRECTORIES(/usr/local/Cellar/allegro/5.2.7.0/lib)
    file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.7.0/lib/*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(ing1-projet-2021-22-dofus-arena-team-aa ${LIBRARIES})
ENDIF(WIN32)
