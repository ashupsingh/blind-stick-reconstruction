"""New reconstruction, 2026-10-23. Demo inputs are synthetic, not historical results."""
def feedback(distance_cm, now):
    if distance_cm is None or not 2<=distance_cm<=400:return {'fault':True,'vibrate':False}
    if distance_cm>120:return {'fault':False,'vibrate':False}
    period=.2 if distance_cm<40 else .6 if distance_cm<80 else 1.0
    return {'fault':False,'vibrate':now%period<period/3}
def demo():
    assert feedback(None,0)['fault'];assert feedback(20,0)['vibrate']
    assert not feedback(150,0)['vibrate']
    return {'near':feedback(20,0),'far':feedback(150,0)}

if __name__ == "__main__":
    import json
    print(json.dumps(demo(), indent=2))
