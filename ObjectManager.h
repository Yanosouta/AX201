#ifndef ___OBJECTMANAGER_H___
#define ___OBJECTMANAGER_H___

#include <list>
#include <memory>
#include <string>
#include "ObjectBase.h"
#include <vector>
#include <algorithm>

class ObjectBase;

class ObjectManager
{
	friend class ObjectBase;
	using ObjectPool = std::list<std::shared_ptr<ObjectBase>>;
	using vObjectPool = std::vector<std::shared_ptr<ObjectBase>>;

private:
	// オブジェクトプール
	static ObjectPool m_AppendObjectPool;
	static ObjectPool m_ObjectPool;
	static ObjectPool m_DestroyObjectPool;
public:
	// コンストラクタ
	ObjectManager() {}
	// デストラクタ
	~ObjectManager() {
		m_AppendObjectPool.clear();
		m_ObjectPool.clear();
		m_DestroyObjectPool.clear();
	}

	// オブジェクトを作成
	template <class T>
	static std::shared_ptr<ObjectBase> CreateObject(std::string name, std::string tag = TagName::Untagged) {
		std::shared_ptr<ObjectBase> pObject = std::make_shared<T>(name, tag);
		// 自分自身を指すポインタをセットする
		pObject->m_this = pObject;
		// オブジェクトプールにオブジェクトを追加
		AddObject(pObject);
		return pObject;
	}

	// オブジェクトを登録
	static void AddObject(std::shared_ptr<ObjectBase> pObject) {
		// オブジェクトプールにオブジェクトを追加
		m_AppendObjectPool.push_front(pObject);
	}

	// オブジェクトを削除
	static void RemoveObject(std::shared_ptr<ObjectBase> pObject) {
		// 削除プールにオブジェクトを追加
		m_DestroyObjectPool.push_back(pObject);
		// オブジェクトの削除判定をONに
		pObject->SetDestroy(true);
	}

	// オブジェクトを全て削除
	static void DestroyAllObject() {
		// オブジェクトプールを全て削除
		m_AppendObjectPool.clear();
		m_ObjectPool.clear();
	}

	// オブジェクトの取得
	static std::shared_ptr<ObjectBase> FindObjectWithName(const std::string& name) {
		for (auto it = m_AppendObjectPool.begin(); it != m_AppendObjectPool.end(); it++) {
			// 名前が同じか判定する
			if ((*it)->GetName() == name)
				return (*it);
		}
		for (auto it = m_ObjectPool.begin(); it != m_ObjectPool.end(); it++) {
			// 名前が同じか判定する
			if ((*it)->GetName() == name)
				return (*it);
		}
		// 見つからなかったらnullptrを返す
		return nullptr;
	}

	// オブジェクトの取得
	static std::shared_ptr<ObjectBase> FindObjectWithTag(const std::string& tag) {
		for (auto it = m_AppendObjectPool.begin(); it != m_AppendObjectPool.end(); it++) {
			// タグ名が同じか判定する
			if ((*it)->GetTag() == tag)
				return (*it);
		}
		for (auto it = m_ObjectPool.begin(); it != m_ObjectPool.end(); it++) {
			// タグ名が同じか判定する
			if ((*it)->GetTag() == tag)
				return (*it);
		}
		// 見つからなかったらnullptrを返す
		return nullptr;
	}

	// オブジェクトの取得
	static std::list<std::shared_ptr<ObjectBase>> FindObjectListWithTag(const std::string& tag) {
		std::list< std::shared_ptr<ObjectBase>> pObjList;
		for (auto it = m_AppendObjectPool.begin(); it != m_AppendObjectPool.end(); it++) {
			// タグ名が同じか判定する
			if ((*it)->GetTag() == tag)
				// リストに追加
				pObjList.push_back((*it));
		}
		for (auto it = m_ObjectPool.begin(); it != m_ObjectPool.end(); it++) {
			// タグ名が同じか判定する
			if ((*it)->GetTag() == tag)
				// リストに追加
				pObjList.push_back((*it));
		}
		// オブジェクトリストを返す。
		return pObjList;
	}

	// オブジェクトの前更新
	static void FixedUpdate() {
		for (auto it = m_ObjectPool.begin(); it != m_ObjectPool.end(); it++)
			if (!(*it)->GetDestroy())
				(*it)->FixedUpdate();
	}
	// オブジェクトの更新
	static void Update();
	// オブジェクトの後更新
	static void LateUpdate() {
		for (auto it = m_ObjectPool.begin(); it != m_ObjectPool.end(); it++)
			if (!(*it)->GetDestroy())
				(*it)->LateUpdate();
		Delete();
	}
	// オブジェクトの描画
	static void Draw() {
		vObjectPool drawObjPool;
		for (auto it = m_ObjectPool.begin(); it != m_ObjectPool.end(); it++)
			drawObjPool.push_back(*it);
		// 描画順レイヤーによってソートする
		std::sort(drawObjPool.begin(), drawObjPool.end());
		for (auto it = drawObjPool.begin(); it != drawObjPool.end(); it++)
			if (!(*it)->GetDestroy())
				(*it)->Draw();
	}

private:
	// 削除オブジェクトを削除
	static void Delete() {
		// リストが空なら抜ける
		if (m_DestroyObjectPool.empty()) return;
		// リストの中身を削除
		for (auto DestroyItr = m_DestroyObjectPool.begin(); DestroyItr != m_DestroyObjectPool.end(); ++DestroyItr) {
			m_ObjectPool.remove(*DestroyItr);
		}
		m_DestroyObjectPool.clear();
	}
};

#endif //!___OBJECTMANAGER_H___
