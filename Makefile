

all: Array

depend: Array-depend

clean generated realclean check-syntax $(CUSTOM_TARGETS):
	@$(MAKE) -f Makefile.Array $(@)

.PHONY: Array
Array:
	@$(MAKE) -f Makefile.Array all

.PHONY: Array-depend
Array-depend:
	@$(MAKE) -f Makefile.Array depend

project_name_list:
	@echo Array
