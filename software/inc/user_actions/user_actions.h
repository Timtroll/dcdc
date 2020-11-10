#ifndef _USER_ACTIONS_H_
#define _USER_ACTIONS_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "../parser/d_base.h"
#include "../charger/charger_core.h"
#include "parser.h"
#include "user_comand.h"


#define URESP_MAX_LEN 150
char * get_user_response(void);

#endif//_USER_ACTIONS_H_

