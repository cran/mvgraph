.First.lib <- function(lib, pkg) {
	library.dynam("mvgraph", pkg, lib)
	#dyn.load(paste(lib, "/", pkg, "/libs/mvgraph.so", sep=""))
}

