import numpy as np
from scipy.sparse import rand
from scipy.optimize import lsq_linear
import pandas as pd

rng = np.random.default_rng()

m = 1
n = 6

A = rand(m, n, density=1e-4, random_state=rng)
b = rng.standard_normal(m)

lb = rng.standard_normal(n)
ub = lb + 1

res = lsq_linear(A, b, bounds=(lb, ub), lsmr_tol='auto', verbose=1).x
res = res.real.astype()
print(f"res type: {type(res)}, dtype: {type(res[0])}")

thrust_map = pd.read_csv("/Users/microgz/Buzzzzzzz/hornet9/combined/controls_ws/controls_core/controls_core/thrust_map.csv").values
thrust_converted = thrust_map[np.searchsorted(thrust_map[:, 0], res, side="left"), 1]
# type(thrust_converted[0].item())

print(thrust_converted, type(thrust_converted), type(thrust_converted[0]))
print(type(thrust_converted.astype(dtype=int, casting='unsafe', subok=False)[0])) # testing astyp doesnt seem to work only converts to a numpy.int the can library may not support this data type

# this works may have a more efficient way to do it 
def convert_to_int(arr: np.ndarray) -> tuple[int]:
    return [int(x) for x in np.nditer(arr)]

thrust_converted = convert_to_int(thrust_converted)
print(thrust_converted, type(thrust_converted), type(thrust_converted[0]))

data = np.array([1,2,3,4,5,6], dtype=np.int64)
print(type(data[0]))