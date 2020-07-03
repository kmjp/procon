
import datetime
dat = datetime.datetime.strptime(raw_input(), "%Y/%m/%d")
dat += datetime.timedelta(days=2)
print dat.strftime("%Y/%m/%d")
