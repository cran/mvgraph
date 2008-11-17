multiGraph <- function(x) {

        if(!(is.data.frame(x) || is.matrix(x)) ) stop("Argument x has to be matrix or data.frame.")

        k = dim(x)[[2]]
        if( !exists(".SSenv", envir=.GlobalEnv) ) {
            .SSenv <<- new.env()
        }
        ssname <- paste( deparse(substitute(x)), "_mg", sep="")
        if( exists( ssname, envir=.SSenv, inherits=FALSE ) ) {
            myObj <- get( ssname, envir=.SSenv )
        }
        else {
            sel = rep(FALSE, k)
            simple = TRUE
            bordered = FALSE
            diamonds  = FALSE
            add = FALSE
            labels = FALSE

		if ( any(class(x)=="DASData") ) {
	      	if ( is.null ( attributes(x)$coordinates[1] )) xC <- 1
	      	else xC <- (1:k)[colnames(x)==attributes(x)$coordinates[1]][1]
	      	if ( is.null ( attributes(x)$coordinates[2] )) yC <- 2
	      	else yC <- (1:k)[colnames(x)==attributes(x)$coordinates[2]][1]
	      }
	    	else {
	      	xC <- 1
	      	yC <- 2
	      }
            myObj <- list(index = 0, selected = sel, xC = xC, yC = yC, simple = TRUE, bordered = FALSE, diamonds = FALSE, add = FALSE, labels = FALSE )
        }



        temp = .C("multiGraph", as.integer(k), as.character(dimnames(x)[[2]]), as.logical(myObj$selected), as.integer(myObj$xC), as.integer(myObj$yC), as.logical(myObj$add), as.logical(myObj$labels), as.integer(myObj$index), as.logical(myObj$simple), as.logical(myObj$bordered), as.logical(myObj$diamonds), as.logical(FALSE), PACKAGE="mvgraph")

        ok = temp[[12]]
        if(!ok) stop("Aborted")

        selected = temp[[3]]
        xCoord = x[, temp[[4]] ]
        yCoord = x[, temp[[5]] ]
        addToExisting = temp[[6]]
        labels = temp[[7]]
        index = temp[[8]]
        simple = temp[[9]]
        bordered = temp[[10]]
        diamonds = temp[[11]]

        myObj <- list(index = index, selected = selected, xC = temp[[4]], yC = temp[[5]], simple = simple, bordered = bordered, diamonds = diamonds, add = addToExisting, labels = labels )
        assign( ssname, myObj, envir=.SSenv)

        if(labels == FALSE) {
                labels = NULL
        }
        else {
                labels = dimnames(x)[[1]]
        }

        rangex = max(xCoord) - min(xCoord)
        rangey = max(yCoord) - min(yCoord)
        scale = min(rangex, rangey)/15

        locleg = c(max(xCoord), max(yCoord)) - c(rangex, rangey)/10

        if(any(selected)) {
                if(index == 0) { #stars
                        if(simple == TRUE) {
                                # source("suns.R")
                                suns(x[, selected], locations=cbind(xCoord, yCoord), key.loc=locleg, len=scale, xlim=c(min(xCoord), max(xCoord)), ylim=c(min(yCoord), max(yCoord)), labels = labels, add = addToExisting)
command <- paste("suns(x[, ", selected, "], locations=cbind(",xCoord,",",yCoord,"), key.loc=",locleg, ", len=", scale, ", xlim=c(min(", xCoord, "), max(", xCoord, ")), ylim=c(min(", yCoord, "), max(", yCoord, ")), labels =", labels, ", add =",  addToExisting, ")", sep="")
                        }
                        if(bordered == TRUE) {
                                stars(x[, selected], locations=cbind(xCoord, yCoord), key.loc=locleg, len=scale, xlim=c(min(xCoord), max(xCoord)), ylim=c(min(yCoord), max(yCoord)), draw.segments=FALSE, labels = labels, add = addToExisting)
command <- paste("stars(x[,", selected, "], locations=cbind(", xCoord, ",", yCoord, "), key.loc=", locleg, ", len=", scale, ", xlim=c(min(", xCoord, "), max(", xCoord, ")), ylim=c(min(", yCoord, "), max(", yCoord, ")), draw.segments=FALSE, labels =", labels, ", add = ", addToExisting, ")", sep="")
                        }
                        if(diamonds == TRUE) {
                                stars(x[, selected], locations=cbind(xCoord, yCoord), key.loc=locleg, len=scale, xlim=c(min(xCoord), max(xCoord)), ylim=c(min(yCoord), max(yCoord)), draw.segments=FALSE, radius=FALSE, labels = labels, add = addToExisting)
command <- paste("stars(x[,", selected, "], locations=cbind(", xCoord, ",", yCoord, "), key.loc=", locleg,", len=", scale, ", xlim=c(min(", xCoord, "), max(", xCoord, ")), ylim=c(min(", yCoord, "), max(", yCoord, ")), draw.segments=FALSE, radius=FALSE, labels = ", labels, ", add =", addToExisting, ")", sep="")
                        }
                }
                if(index == 1) { #segments
                        stars(x[, selected], locations=cbind(xCoord, yCoord), key.loc=locleg, len=scale, xlim=c(min(xCoord), max(xCoord)), ylim=c(min(yCoord), max(yCoord)), draw.segments=TRUE, labels = labels, add = addToExisting)
command <- paste("stars(x[,", selected, "], locations=cbind(", xCoord, ",", yCoord, "), key.loc=", locleg, ", len=", scale, ", xlim=c(min(", xCoord, "), max(", xCoord, ")), ylim=c(min(", yCoord, "), max(", yCoord, ")), draw.segments=TRUE, labels = ", labels, ", add =", addToExisting, ")", sep="")
                }
                if(index == 2) { # boxes
                        # source("boxes.R")
                        boxes(x[, selected], locations=cbind(xCoord, yCoord), key.loc=locleg, len=scale, leglen=scale, xlim=c(min(xCoord), max(xCoord)), ylim=c(min(yCoord), max(yCoord)), labels = labels, add = addToExisting)
command <- paste("boxes(x[,", selected, "], locations=cbind(", xCoord, ",", yCoord, "), key.loc=", locleg, ", len=", scale, ", leglen=", scale, ", xlim=c(min(", xCoord, "), max(", xCoord, ")), ylim=c(min(", yCoord, "), max(", yCoord, ")), labels = ", labels, ", add = ", addToExisting, ")", sep="")
                }
                if(index == 3) { #polygons
                        # source("polys.R")
                        polys(x[, selected], locations=cbind(xCoord, yCoord), key.loc=locleg, factx=rangex/30, facty=1, xlim=c(min(xCoord), max(xCoord)), ylim=c(min(yCoord), max(yCoord)), labels = labels, add = addToExisting)
command <- paste("polys(x[,", selected, "], locations=cbind(", xCoord, ",", yCoord, "), key.loc=", locleg, ", factx=", rangex, "/30, facty=1, xlim=c(min(", xCoord, "), max(", xCoord, ")), ylim=c(min(", yCoord, "), max(" ,yCoord, ")), labels = ", labels, ", add =", addToExisting, ")", sep="")
                }
                if(index == 4) { #trees
                        # source("trees.R")
                        tree(x[, selected], locations=cbind(xCoord, yCoord), key.loc=locleg, wmax=120, wmin=30, len=scale/20, leglen=scale/6, lh = 30, xlim=c(min(xCoord), max(xCoord)), ylim=c(min(yCoord), max(yCoord)), labels = labels, add = addToExisting)
command <- paste("tree(x[,", selected, "], locations=cbind(", xCoord, ",", yCoord, "), key.loc=", locleg, ", wmax=120, wmin=30, len=", scale, "/20, leglen=", scale, "/6, lh = 30, xlim=c(min(", xCoord, "), max(", xCoord, ")), ylim=c(min(", yCoord, "), max(", yCoord, ")), labels =", labels, ", add =", addToExisting, ")", sep="")
                }
                if(index == 5) { # castles
                        # source("trees.R")
                        tree(x[, selected], locations=cbind(xCoord, yCoord), key.loc=locleg, wmax=0, wmin=0, len=scale/10, leglen=scale/6, lh = 10, xlim=c(min(xCoord), max(xCoord)), ylim=c(min(yCoord), max(yCoord)), labels = labels, add = addToExisting)
command <- paste("tree(x[,", selected, "], locations=cbind(", xCoord, ",", yCoord, "), key.loc=", locleg, ", wmax=0, wmin=0, len=", scale, "/10, leglen=", scale, "/6, lh = 10, xlim=c(min(", xCoord, "), max(", xCoord, ")), ylim=c(min(", yCoord, "), max(", yCoord, ")), labels =", labels, ", add =", addToExisting, ")", sep="")
                }
        }
#	list(selected = selected, xCoord = xCoord, yCoord = yCoord, add = addToExisting, labels = labels)
	if ( any(class(x)=="DASData") ) {
		command
	}
}
