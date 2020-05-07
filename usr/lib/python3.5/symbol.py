#! /usr/bin/python3.5

"""Non-terminal symbols of Python grammar (from "graminit.h")."""

#  This file is automatically generated; please don't muck it up!
#
#  To update the symbols in this file, 'cd' to the top directory of
#  the python source tree after building the interpreter and run:
#
#    ./python Lib/symbol.py

#--start constants--
single_input = 256
file_input = 257
eval_input = 258
decorator = 259
decorators = 260
decorated = 261
async_funcdef = 262
funcdef = 263
parameters = 264
typedargslist = 265
tfpdef = 266
varargslist = 267
vfpdef = 268
stmt = 269
simple_stmt = 270
small_stmt = 271
expr_stmt = 272
testlist_star_expr = 273
augassign = 274
del_stmt = 275
pass_stmt = 276
flow_stmt = 277
break_stmt = 278
continue_stmt = 279
return_stmt = 280
yield_stmt = 281
raise_stmt = 282
import_stmt = 283
import_name = 284
import_from = 285
import_as_name = 286
dotted_as_name = 287
import_as_names = 288
dotted_as_names = 289
dotted_name = 290
global_stmt = 291
nonlocal_stmt = 292
assert_stmt = 293
compound_stmt = 294
async_stmt = 295
if_stmt = 296
while_stmt = 297
for_stmt = 298
try_stmt = 299
with_stmt = 300
with_item = 301
except_clause = 302
suite = 303
test = 304
test_nocond = 305
lambdef = 306
lambdef_nocond = 307
or_test = 308
and_test = 309
not_test = 310
comparison = 311
comp_op = 312
star_expr = 313
expr = 314
xor_expr = 315
and_expr = 316
shift_expr = 317
arith_expr = 318
term = 319
factor = 320
power = 321
atom_expr = 322
atom = 323
testlist_comp = 324
trailer = 325
subscriptlist = 326
subscript = 327
sliceop = 328
exprlist = 329
testlist = 330
dictorsetmaker = 331
classdef = 332
arglist = 333
argument = 334
comp_iter = 335
comp_for = 336
comp_if = 337
encoding_decl = 338
yield_expr = 339
yield_arg = 340
#--end constants--

sym_name = {}
for _name, _value in list(globals().items()):
    if type(_value) is type(0):
        sym_name[_value] = _name


def _main():
    import sys
    import token
    if len(sys.argv) == 1:
        sys.argv = sys.argv + ["Include/graminit.h", "Lib/symbol.py"]
    token._main()

if __name__ == "__main__":
    _main()
