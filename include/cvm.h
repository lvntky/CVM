#pragma once


#ifdef _WIN32
  #define CVM_EXPORT __declspec(dllexport)
#else
  #define CVM_EXPORT
#endif

CVM_EXPORT void cvm();
