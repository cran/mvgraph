\name{spin}
\alias{spin}
\title{Spin and Brush}
\description{
  Visualize 3d data
}
\usage{
spin(x, y=0, z=0, groups=NULL)
}
\arguments{
	\item{x}{Matrix or data.frame containing data. When x is one-dimensional, y and z have to be supplied.}
	\item{y}{Optional vector argument, when x is a vector}
	\item{z}{Optional vector argument, when x is a vector}
	\item{groups}{Group factor; has to be between 0 and 6}
}
\details{
	Spin and Brush is a three-dimensional data viewing program which offers the possibility to rotate and zoom. Data points can be clustered by using different colors and identified by name or selection.
}
\value{
	spin returns a data.frame consisting of the three-dimensional data and an additional group factor depending on the brushed data points.
}
\examples{
	#data(swiss)
	#spin(swiss)
}
\keyword{file}

