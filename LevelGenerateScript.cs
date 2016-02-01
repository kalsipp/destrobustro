using UnityEngine;
using System.Collections;

public class LevelGenerateScript : MonoBehaviour
{

	// Use this for initialization
	public Transform Tile;
	ResourcePoolScript ResourcePool;
	public int MaxSize;
	public Transform Bullet;
	void Awake()
	{
		width = MaxSize;
		height = MaxSize;
		TileGrid = new Transform[width, height];
		Grid = new int[height,width];
		for (int x = 0; x < width; x++)
		{
			for(int y = 0; y < height; y++)
			{
				Transform newTile = Instantiate(Tile);
				newTile.transform.position = new Vector3(x*3, 0, y*3);
				newTile.gameObject.SetActive(false);
				TileGrid[y, x] = newTile;
			}
		}
		DX = new int[] {0, 0, 1, -1};
		DY = new int[] {1, -1, 0, 0};
		OPP = new int[] {1, 0, 3, 2};
		//Carve (0, 0);
		ResourcePool = GameObject.FindGameObjectWithTag("ResourcePool").GetComponent<ResourcePoolScript>();

		//PlaceRoom();

	}
	void Start()
	{
		//PlacePickups();
		//PlaceEnemies();
	}
	public void GenerateMap(int size, int nrPickups, int nrOfEnemies, float pRooms)
	{
		PercentageRooms = pRooms;
		width = size;
		NumberOfPickups = nrPickups;
		NumberOfEnemies = nrOfEnemies;
		height = width;
		print (height);
		print (width);




		for (int x = 0; x < width; x++)
		{
			for(int y = 0; y < height; y++)
			{
				TileGrid[y, x].gameObject.SetActive(true);
			}
		}
		Carve(0,0);
		PlaceRoom ();
		PlacePickups();
		PlaceEnemies();
	}
	public void DeConstructMap()
	{
		for(int x = 0; x < width; x++)
		{
			for(int y = 0; y < height; y++)
			{
				TileGrid[y, x].GetComponent<BlockScript>().ClosePaths();
				TileGrid[y, x].gameObject.SetActive(false);
			}
		}
	}
	public int NumberOfPickups;
	public int NumberOfEnemies;
	void PlaceEnemies()
	{
		int enemies = 0;
		while (true)
		{
			if(enemies>= NumberOfEnemies)
			{
				break;
			}
			int cy = Random.Range(1, height-1);
			int cx = Random.Range(1, width-1);
			Transform tile = TileGrid[cy, cx];
			if(!tile.GetComponent<BlockScript>().hasEnemy)
			{
				tile.GetComponent<BlockScript>().hasEnemy = true;
				Transform pickup = ResourcePool.GetItem(4);
				pickup.transform.position = new Vector3(cx*3, 1.54f, cy*3);
				enemies++;
			}
		}
	}
	void PlacePickups()
	{
		int pickups = 0;
		while (true)
		{
			if(pickups>= NumberOfPickups)
			{
				break;
			}
			int cy = Random.Range(1, height-1);
			int cx = Random.Range(1, width-1);
			Transform tile = TileGrid[cy, cx];
			if(!tile.GetComponent<BlockScript>().hasItem)
			{
				tile.GetComponent<BlockScript>().hasItem = true;
				Transform pickup = ResourcePool.GetItem(3);
				pickup.transform.position = new Vector3(cx*3, 1.54f, cy*3);
				pickup.GetComponent<PickUpScript>().SetPickup();
				pickups++;
			}
		}
	}
	// Update is called once per frame
	int[,] Grid;
	Transform[,] TileGrid;
	Stack items;
	int[] DX;
	int[] DY;
	int[] OPP;
	int[] dirs = {0, 1, 2, 3}; //N S E W
	bool doOnce;
	void Carve (int cx, int cy)
	{
		float timer = Time.time;
		int[] dir = RandomArray (dirs);
		foreach (int d in dir) {
			//int n = d - 1;
			int nx = cx + DX [d];
			int ny = cy + DY [d];
			if (nx < width && nx >= 0 && ny < height && ny >= 0) {
				if (!TileGrid[ny, nx].GetComponent<BlockScript>().Carved) {
					PlaceTile(cx, cy, nx, ny, d);
					TileGrid[ny, nx].GetComponent<BlockScript>().Carved = true;
					Grid [cy, cx] = d;
					Grid [ny, nx] = OPP [d];
					Carve (nx, ny);
				}
			}
		}
	}
	public float PercentageRooms;
	int nrOfRooms;
	int NumberOfWantedRooms;
	void PlaceRoom()
	{
		NumberOfWantedRooms = (int)((PercentageRooms/100)*width*height);
		//print ("WantedRooms "+NumberOfWantedRooms);
		bool notDone = true;
		while (notDone)
		{
			int ny = Random.Range(1, height-1);
			int nx = Random.Range(1, width-1);
			Transform tile = TileGrid[ny, nx];
			//print ("On Block nx = " + nx*3 + " ny = " + ny*3);

			for(int i = 0; i < 4; i++){
				tile.GetComponent<BlockScript>().OpenUpPath(i);
				//print ("Opens up " + i); 
				int diffx = nx+DX[i];
				int diffy = ny+DY[i];
				//print ("Goes diffx = " + diffx*3 + " diffy = " + diffy*3);
				//print ("Opens up " + OPP[i]);
				TileGrid[diffy, diffx].GetComponent<BlockScript>().OpenUpPath(OPP[i]);
			}
			tile.GetComponent<BlockScript>().isRoom = true;
			nrOfRooms++;
			GrowRoom(nx, ny);
			if(nrOfRooms >= NumberOfWantedRooms)
			{
				break;
			}

		}
	}
	void GrowRoom(int cx, int cy)
	{
		//Transform currentTile = TileGrid[pos.y, pos.x];
		if(nrOfRooms >= NumberOfWantedRooms)
		{
			return;
		}
		int[] dir = RandomArray(dirs);

		foreach(int d in dir)
		{
			int nx = cx + DX[d];
			int ny = cy + DY[d];
			if(nx < width-1 && nx > 1 && ny < height -1 && ny > 1)
			{
				if(!TileGrid[ny, nx].GetComponent<BlockScript>().isRoom)
				{
					for(int i = 0; i < 4; i++){
						TileGrid[ny, nx].GetComponent<BlockScript>().OpenUpPath(i);
						int diffx = cx+DX[i];
						int diffy = cy+DY[i];
						TileGrid[diffy, diffx].GetComponent<BlockScript>().OpenUpPath(OPP[i]);
					}
					TileGrid[ny, nx].GetComponent<BlockScript>().isRoom = true;
					nrOfRooms++;
					//GrowRoom(ny, nx);
				}
			}
		}
	}
	public int width;
	int height;
	public int[,] GetGrid()
	{
		return Grid;
	}
	public Transform[,] GetTileGrid()
	{
		return TileGrid;
	}
	public Transform GetSpecificTileGrid(int x, int y)
	{
		return TileGrid[y, x];
	}
	public float GetMapSize()
	{
		return width;
	}
	void PlaceTile (int cx, int cy, int nx, int ny, int d)
	{
		TileGrid[cy,cx].GetComponent<BlockScript>().OpenUpPath(d);
		TileGrid[ny, nx].GetComponent<BlockScript>().OpenUpPath(OPP[d]);
		TileGrid[cy, cx].GetComponent<BlockScript>().Direction = d;


	}

	void Update ()
	{

	}

	int[] RandomArray (int[] a)
	{
		for (int j = 0; j < a.Length; j++) {
			int r = j + (int)(Random.Range (0f, 1f) * (a.Length - j));
			int t = a [r];
			a [r] = a [j];
			a [j] = t;
		}
		return a;
	}



}
