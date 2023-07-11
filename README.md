# Morloc matrix module

Currently we offer only C++ support through the Eigen library. This library is
suitable because it is header-only (no dependencies needed), has a generic API
that meshes well with morloc philosophy, and has good performance (or so the
Internet says). Python support can be added eventually through numpy. R can be
added even more easily using native matrix types.

The `Matrix` general type is currently not parameterized over dimension. It
takes a single parameter, the stored value type. For example `Matrix Real`.
