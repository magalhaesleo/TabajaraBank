#pragma once

#ifdef TABAJARABANKAPPLICATION_EXPORTS
#define TABAJARABANKAPPLICATION_API __declspec(dllexport)   
#else  
#define TABAJARABANKAPPLICATION_API __declspec(dllimport)   
#endif