\name{multiGraph}
\alias{multiGraph}
\title{Draw multivariate Graphics}
\description{
  Draw multivariate Graphics
}
\usage{
multiGraph(x)
}
\arguments{
	\item{x}{Matrix or data.frame}
}
\details{
	Multivariate Graphics was made for datasets which include geographical coordinates. Data points are drawn as "multivariate items" on a geographical background map (the locations of the items are specified by their coordinates) which makes it possible to show the values of many variables at a time. Several multivariate items such as stars, trees or castles are provided.
}
\value{
	If multiGraph is started via DASplusR, a string, representing the command, is returned.
}
\examples{
	#data(swiss)
	#multiGraph(swiss)
}
\keyword{file}

