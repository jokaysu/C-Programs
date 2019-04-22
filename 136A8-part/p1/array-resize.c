#include "array-resize.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

//match(here, id, tar) determins if here is the same 
//  as tar since id.

bool match(const char *here, int id, const char *tar) {
	int l = strlen(tar);
	for (int i = 0; i < l; ++i) 
		if (here[id + i] != tar[i])
			return false;
	return true;
}

char *replace(char *s, const char *find, const char *rep) {
	int n = strlen(s);
	int m = strlen(find);
	int k = strlen(rep);
	char *ans = malloc(1 * sizeof(char));
  	ans[0] = '\0';
	int i, j, h, y;
	for (i = 0, j = 0; i < n;) {
		if (match(s, i, find)) {
    		y = strlen(ans);
   			ans = realloc(ans, (y + k + 1) * sizeof(char));
      		ans[y + k] = ans[y];
			for (h = 0; h < k; ++h) ans[j + h] = rep[h];
			j += k;
			i += m;
		} else {
      		y = strlen(ans);
			ans = realloc(ans, (y + 2) * sizeof(char));
      		ans[y + 1] = ans[y];
			ans[j] = s[i];
			j++;
			i++;
		}
  }
	return ans;
}

