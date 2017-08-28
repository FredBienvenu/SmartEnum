#include <iostream>
#include <stdio.h>

#include "SmartEnum.h"

#define SMARTENUM_IceCreamFlavor(_)\
    _(CHOCOLATE, 56)\
    _(VANILLA, 27)\
    _(STRAWBERRY, 11)\
    _(PISTACHIO, 72)\
    _(HAM, 40)

// declaration of the enum and the associated functions
SMARTENUM_DECLARE(SMARTENUM_IceCreamFlavor, IceCreamFlavor)
// definitions of the functions
SMARTENUM_DEFINE(SMARTENUM_IceCreamFlavor, IceCreamFlavor)

void dump_IceCreamFlavor()
{
	size_t sizeof_IceCreamFlavor = $(IceCreamFlavor, size)();
	size_t i;
	
	printf("typedef enum\n");
	printf("{\n");
	
	for(i = 0; i < sizeof_IceCreamFlavor; ++i)
	{
		IceCreamFlavor flavor = $(IceCreamFlavor, at)(i);
		if($(IceCreamFlavor, isValid)(flavor))
		{
			printf("\t%s = %d,\n", $(IceCreamFlavor, toString)(flavor), flavor);
		}
	}
	printf("}\n");
	printf("%s;\n", $(IceCreamFlavor, name)());
	
	printf("--------\n");
	{
		IceCreamFlavor first, last, min, max;
		first = $(IceCreamFlavor, first)();
		last = $(IceCreamFlavor, last)();
		min = $(IceCreamFlavor, min)();
		max = $(IceCreamFlavor, max)();
		
		printf("Statistics:\n");
		printf("\t- first: %s (%d)\n", $(IceCreamFlavor, toString)(first), first);
		printf("\t- last: %s (%d)\n", $(IceCreamFlavor, toString)(last), last);
		printf("\t- min: %s (%d)\n", $(IceCreamFlavor, toString)(min), min);
		printf("\t- max: %s (%d)\n", $(IceCreamFlavor, toString)(max), max);
	}
	printf("--------\n");
}

int main(int argc, char *argv[])
{
	char string_flavor[100] = "";
	bool flavor_entered = false;
	IceCreamFlavor flavor;
	
	dump_IceCreamFlavor();
	
	while(!flavor_entered)
	{
		printf("Please enter a valid flavor: ");
		scanf("%s", string_flavor);
		
        if($(IceCreamFlavor, isStringValid)(string_flavor))
        {
            flavor = $(IceCreamFlavor, fromString)(string_flavor);
            flavor_entered = true;
        }
        else
        {
            printf("%s is not a valid flavor !\n", string_flavor);
        }		
	}
	
    if($(IceCreamFlavor, isValid)(flavor))
    {
        printf("%s is a valid flavor, its value is %d !\n",  $(IceCreamFlavor, toString)(flavor), flavor);
    }
    else
    {
        printf("Unknow flavor value %d !\n", flavor);
    }


	return 0;
}
