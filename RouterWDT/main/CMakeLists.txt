# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS "")
set(APP_SOURCES    "")
set(PROJECT_SOURCE_DIR ".")

file(GLOB_RECURSE APP_SOURCES_TOP
       ${PROJECT_SOURCE_DIR}/*.cpp
       ${PROJECT_SOURCE_DIR}/*.c
       )
       
list(APPEND APP_SOURCES ${APP_SOURCES_TOP})        
       
foreach (sourcefile ${APP_SOURCES})
    get_filename_component(fileName ${sourcefile} NAME_WLE)
    get_filename_component(dirname  ${sourcefile} DIRECTORY)
        
	list(APPEND COMPONENT_SRCS "${dirname}/${fileName}.cpp")
endforeach (sourcefile ${APP_SOURCES})

set(COMPONENT_ADD_INCLUDEDIRS ${PROJECT_SOURCE_DIR})

file(GLOB_RECURSE APP_HEADERS_TOP
       ${PROJECT_SOURCE_DIR}/*.h
       ${PROJECT_SOURCE_DIR}/*.hpp
       ${PROJECT_SOURCE_DIR}/*.tpp)
       
list(APPEND APP_HEADERS ${APP_HEADERS_TOP})    

foreach (headerfile ${APP_HEADERS})   
    get_filename_component(dirname  ${headerfile} DIRECTORY)
        
	list(APPEND COMPONENT_ADD_INCLUDEDIRS "${dirname}")
endforeach (headerfile ${APP_HEADERS})   

register_component()
