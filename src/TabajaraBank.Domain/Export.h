#pragma once

#ifdef TABAJARABANKDOMAIN_EXPORTS
#define TABAJARABANKDOMAIN_API __declspec(dllexport)   
#else  
#define TABAJARABANKDOMAIN_API __declspec(dllimport)   
#endif