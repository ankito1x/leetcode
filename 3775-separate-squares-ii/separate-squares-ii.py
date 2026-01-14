class Solution:
    def separateSquares(self, squares):
        events = []
        xs = set()

        for x, y, s in squares:
            events.append((y, 1, x, x + s))
            events.append((y + s, -1, x, x + s))
            xs.add(x)
            xs.add(x + s)

        events.sort()
        xs = sorted(xs)
        x_id = {x: i for i, x in enumerate(xs)}

        n = len(xs) - 1
        count = [0] * (4 * n)
        length = [0] * (4 * n)

        def push_up(idx, l, r):
            if count[idx] > 0:
                length[idx] = xs[r] - xs[l]
            elif l + 1 == r:
                length[idx] = 0
            else:
                length[idx] = length[idx * 2] + length[idx * 2 + 1]

        def update(idx, l, r, ql, qr, val):
            if qr <= l or r <= ql:
                return
            if ql <= l and r <= qr:
                count[idx] += val
                push_up(idx, l, r)
                return
            mid = (l + r) // 2
            update(idx * 2, l, mid, ql, qr, val)
            update(idx * 2 + 1, mid, r, ql, qr, val)
            push_up(idx, l, r)

        # Step 1: total union area
        prev_y = events[0][0]
        total_area = 0

        for y, typ, x1, x2 in events:
            covered = length[1]
            total_area += covered * (y - prev_y)
            update(1, 0, n, x_id[x1], x_id[x2], typ)
            prev_y = y

        half = total_area / 2

        # Step 2: find answer
        prev_y = events[0][0]
        curr_area = 0
        count = [0] * (4 * n)
        length = [0] * (4 * n)

        for y, typ, x1, x2 in events:
            covered = length[1]
            height = y - prev_y

            if curr_area + covered * height >= half:
                return prev_y + (half - curr_area) / covered

            curr_area += covered * height
            update(1, 0, n, x_id[x1], x_id[x2], typ)
            prev_y = y

        return prev_y
