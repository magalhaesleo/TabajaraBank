#pragma once

#ifdef TABAJARABANKAPI_EXPORTS
#define TABAJARABANKAPI_API __declspec(dllexport)   
#else  
#define TABAJARABANKAPI_API __declspec(dllimport)   
#endif