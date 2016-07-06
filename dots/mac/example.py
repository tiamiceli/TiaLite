import sys
from ROOT import gSystem
gSystem.Load("libTiaLite_dots")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing dots..."

sys.exit(0)

