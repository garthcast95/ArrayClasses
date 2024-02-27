

all: assignment2

depend: assignment2-depend

clean generated realclean check-syntax $(CUSTOM_TARGETS):
	@$(MAKE) -f Makefile.assignment2 $(@)

.PHONY: assignment2
assignment2:
	@$(MAKE) -f Makefile.assignment2 all

.PHONY: assignment2-depend
assignment2-depend:
	@$(MAKE) -f Makefile.assignment2 depend

project_name_list:
	@echo assignment2
