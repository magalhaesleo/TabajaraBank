#pragma once

#ifdef TABAJARABANKINFRA_EXPORTS
#define TABAJARABANKINFRA_API __declspec(dllexport)   
#else  
#define TABAJARABANKINFRA_API __declspec(dllimport)   
#endif