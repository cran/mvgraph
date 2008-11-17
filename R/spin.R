spin <- function(x, y=0, z=0, groups=NULL) {


        if( !exists(".SSenv", envir=.GlobalEnv) ) {
            .SSenv <<- new.env()
        }
        ssname <- paste( deparse(substitute(x)), "_sb", sep="")
        if( exists( ssname, envir=.SSenv, inherits=FALSE ) ) {
            myObj <- get( paste( deparse(substitute(x)), "_sb", sep=""), envir=.SSenv )
        }
        else {
            if(is.matrix(x) || is.data.frame(x)) {
                n <- dim(x)[[1]]
            }
            else {
                n <- length(x)
            }
            col = c(255, 0, 0, 0, 0, 255, 0, 255, 0, 0, 255, 255, 255, 0, 255, 255, 255, 0)
            gr <- as.factor(rep(0,n))
            selvars <- NULL
            myObj <- list(groups = gr, selected = selvars, colors = col)
        }
	if(is.matrix(x) || is.data.frame(x)) {
		if(dim(x)[2] < 3) stop("Data matrix must have at least three columns")
		if(dim(x)[1] > 10000) stop("Number of points must be less than 10001");

                k <- dim(x)[[2]]


                if(is.data.frame(x)) {
                    d1 <- dimnames(x)[[1]]
                    d2 <- dimnames(x)[[2]]
                }
                else {
                    d1 <- 1:n
                    d2 <- 1:k
                }
                if(is.null(myObj$selected)) {
                    sel <- rep(FALSE, k)
                }
                else {
                    sel <- myObj$selected
                }
                temp1 <- .C("selectvars", as.character(d2), as.logical(sel), as.integer(k), as.logical(FALSE), PACKAGE="mvgraph")

                ok <- temp1[[4]]
                if(!ok) stop("Aborted")

                sel <- temp1[[2]];
                myObj$selected <- sel
                s <- c(1:k)[sel == TRUE]
                if(is.data.frame(x)) {
                    d2 <- c(d2[s[1]], d2[s[2]], d2[s[3]])
                }
                else {
                    d2 <- c("x", "y", "z")
                }
		y <- x[,s[2]]
 		z <- x[,s[3]]
                x <- x[,s[1]]

        }
        else {
            d1 <- 1:length(x)
            d2 <- c("x", "y", "z")
        }
	if(length(x) != length(y)) stop("Vectors must have same length")
	if(length(x) != length(z)) stop("Vectors must have same length")
	if(length(y) != length(z)) stop("Vectors must have same length")
        if(length(x) > 10000) stop("Number of points must be less than 10001");
        if(!is.null(groups)) {
            if(length(groups[as.integer(as.character(groups)) < 0 | as.integer(as.character(groups)) > 6])) stop("Group factor must be between 0 and 6")
            if(length(groups) != length(x)) stop("Group factor must have same length as data")

            myGroups = as.factor(groups)
        }
        else {
            myGroups = myObj$groups
        }
        cols = myObj$colors
	max = max(abs(c(x,y,z)))
        temp <- .C("spin", as.double(x/max), as.double(y/max), as.double(z/max), as.integer(length(x)), as.integer(as.character(myGroups)), as.integer(cols), as.double(max), as.character(d1), as.character(d2), PACKAGE="mvgraph")
        selected <- temp[[5]]
        cols <- temp[[6]]
        myObj$groups <- as.factor(selected)
        myObj$colors <- as.integer(cols)
        assign( ssname, myObj, envir=.SSenv)
	mylist <- list(x, y, z, as.factor(selected))
	names(mylist) <- c(d2[1], d2[2], d2[3], "groups")
        as.data.frame(mylist)
}
