set(PKG helloservicer)
set(PKGSRC 
    helloservicer.cpp 
    helloservicerfactory.cpp
    )
add_library(${PKG} STATIC ${PKGSRC})