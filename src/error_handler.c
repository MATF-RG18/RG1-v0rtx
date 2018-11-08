/**
 * @file error_handler.c
 * @brief 
 * @author Tomislav Jankovic
 * @version 0.1a
 * @date 2018-11-08
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/error_handler.h"

void error_handler(int expression, const char *error_msg)
{
  if(!expression){
    fprintf(stderr, "Error msg dump: %s\nFile: %s | Function: %s | Line: %u\n", error_msg, __FILE__, __func__, __LINE__);
    exit(EXIT_FAILURE);
  }
}

