/* vulnerable function */
int load_array(int *array, unsigned int user_value)
{
	if (user_value >= MAX_ARRAY_ELEMS)
		return 0;

	return array[user_value];
}


/* fixed function */
#include <linux/nospec.h>

int load_array(int *array, unsigned int user_value)
{
	if (user_value >= MAX_ARRAY_ELEMS)
		return 0;

	user_value = array_index_nospec(user_value, MAX_ARRAY_ELEMS);
	return array[user_value];
}
