default: build

OUTDIR = build
RELEASE_PREFIX = release
DEBUG_PREFIX = debug
EXE = vm.exe

build: vm/*.c
		mkdir -p $(OUTDIR)/$(RELEASE_PREFIX)
		gcc vm/*.c -o $(OUTDIR)/$(RELEASE_PREFIX)/$(EXE)

build-debug: vm/*.c
		mkdir -p $(OUTDIR)/$(DEBUG_PREFIX)
		gcc vm/*.c -g -o $(OUTDIR)/$(DEBUG_PREFIX)/$(EXE)

clean:
		rm -rf $(OUTDIR)